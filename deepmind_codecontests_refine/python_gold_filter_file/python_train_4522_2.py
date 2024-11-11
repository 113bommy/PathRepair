# -*- coding: utf-8 -*-
"""
Created on Mon May 11 15:03:20 2020

@author: alexi
"""


class Node():
    
    def __init__(self, parent = None, position = None):
        self.parent = parent
        self.position = position
        self.g = 0
        self.h = 0
        self.f = 0
        
    def __eq__(self, other):
        return self.position == other.position
    
def heuristic(A, B):
    return abs(A[0]-B[0]) + abs(A[1]-B[1])

def Astar(maze, start, end):
    
    start_node = Node(None, start)
    start_node.g = 0
    start_node.h = heuristic(start, end)
    start_node.f = start_node.g + start_node.h
    
    end_node = Node(None, end)
    end_node.g = heuristic(start, end)
    end_node.h = 0
    end_node.f = end_node.g + end_node.h

    open_list = []
    closed_list = []
    
    open_list.append(start_node)
    
    while True:
        
        if len(open_list) == 0:
            return -1
        
        current_node = open_list[0]
        current_index = 0
        
        for index, item in enumerate(open_list):
            if item.f < current_node.f:
                current_node = item
                current_index = index
        
        open_list.pop(current_index)
        closed_list.append(current_node)
        
        if current_node == end_node:
            path = []
            current = current_node
            while current is not None:
                path.append(current.position)
                current = current.parent
            
            return path[::-1]
        else:
            
            children = []
            
            for new_position in [(0, -1),(0, 1),(1, 0),(-1, 0),(-1, -1),(-1, 1),(1, -1),(1, 1)]:
                
                node_position = (current_node.position[0] + new_position[0], current_node.position[1] + new_position[1])
                
                if node_position[0] > (len(maze)-1) or node_position[0] < 0 or node_position[1] > (len(maze[len(maze)-1])-1) or node_position[1] < 0:
                    continue
                
                if maze[node_position[0]][node_position[1]] != 0:
                    continue
                
                new_node = Node(current_node, node_position)
                new_node.g = current_node.g + 1
                new_node.h = heuristic(new_node.position, end)
                new_node.f = new_node.g + new_node.h
                
                children.append(new_node)
                
            visited = False
            
            for child in children:
                for open_child in open_list:
                    if child.position == open_child.position:
                        if child.f < open_child.f:
                            open_child = child
                        visited = True
                
                for closed_child in closed_list:
                    if child.position == closed_child.position:
                        if child.f < closed_child.f:
                            closed_child = child
                        visited = True
                
                if visited:
                    visited = False
                else:
                    open_list.append(child)
                
                


def move_the_king():


    maze = [[0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0],
          ]
    
    
    dic_letters = {'a':0,'b':1,'c':2,'d':3,'e':4,'f':5,'g':6,'h':7}
    dic_numbers = {8:0,7:1,6:2,5:3,4:4,3:5,2:6,1:7}
    dic_move = {(1,0):'D',(-1,0):'U',(0,1):'R',(0,-1):'L',(-1, -1):'LU',(-1, 1):'RU',(1, -1):'LD',(1, 1):'RD'}
    
    start = input()
    end = input()
    
    actual_start = (dic_numbers[int(start[1])],dic_letters[start[0]])
    actual_end = (dic_numbers[int(end[1])],dic_letters[end[0]])
    
    path = Astar(maze, actual_start, actual_end)
    print(len(path)-1)
    
    for i in range(1, len(path)):
        temp = (path[i][0] - path[i-1][0], path[i][1] - path[i-1][1])
        print(dic_move[temp])
    
    
    
move_the_king()     
                