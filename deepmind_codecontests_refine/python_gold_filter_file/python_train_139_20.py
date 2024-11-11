import sys
import math

def games():
    datain = []
    shirts = 0
    homeshirts = []
    awayshirts = []
    
    #Taking input
    teams = int(input())
    for i in range(teams):
        datain.append(input().split())
        
    #Creating homeshirt list
    for i in range(teams):
        homeshirts.append(datain[i][0])

    #Creating awayshirt list
    for i in range(teams):
        awayshirts.append(datain[i][1])

    #Finding pairs
    for i in homeshirts:
        shirts += awayshirts.count(i)

    print(shirts)

games()
