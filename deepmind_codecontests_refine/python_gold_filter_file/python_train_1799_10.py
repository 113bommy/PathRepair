######################################################
############Created by Devesh Kumar###################
#############devesh1102@gmail.com####################
##########For CodeForces(Devesh1102)#################
#####################2020#############################
######################################################


 
import sys 
import heapq 
import copy
import math
import decimal
input = sys.stdin.readline
# import sys.stdout.flush as flush
# from decimal import *
#heapq.heapify(li) 
#
#heapq.heappush(li,4) 
#
#heapq.heappop(li)
#
# &    Bitwise AND Operator    10 & 7 = 2
# |    Bitwise OR Operator    10 | 7 = 15
# ^    Bitwise XOR Operator    10 ^ 7 = 13
 
# <<    Bitwise Left Shift operator    10<<2 = 40
# >>    Bitwise Right Shift Operator
# '''############ ---- Input Functions ---- #######Start#####'''
# n = 100
# parent = [-1 for i in range(n)]
# def find(a):
#     if parent[a] == a:
#         return a
#     else:
#         parent[a] = find(parent[a])
    
# def union(a,b):








    # print(lsp )
def inp():
    return(int(input()))
def inlt(): 
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def insr2():
    s = input()
    s = list(s[:len(s) - 1])
    s = [ord(s[i]) - ord("a") for i in range(len(s))]
    return s
def invr():
    return(map(int,input().split()))
############ ---- Input Functions ---- #######End
# #####   


ans = 0
def pr_list(a):
    print( *a , sep=" ")

def swap(a,b):
    temp = a
    a = b
    b = temp
    return [ a,b]
    # return [b,a]
def pri(a,b):
    s = "? " + str(a) + " " + str(b)
    print(s)
    sys.stdout.flush()
def main():
    tests =  inp()
    # tests = 1
    mod = 1000000007
    limit = 10**18
    ans = 0
    stack = []
    hashm = {}
    arr = []
    heapq.heapify(arr) 

    for test in range(tests):
        x  = inp()
        # x = 1000000000000000000
        arr = 1
        ans = 1
        power = 2
        x = x-1
        while(True):
            # power = power*power
            # print(power)
            arr = 2*arr + power*power
            power =power *2
            if arr <= x:
                x = x - arr
                ans = ans +1
            else:
                break
        print(ans)
            

        


if __name__== "__main__":
    main()
# return least index x such that A[x] > target, or len(A) if no such index exists
