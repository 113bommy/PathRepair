import sys 
import math 
# input = sys.stdin.buffer.readline
strInp = lambda : input().strip().split()
intInp = lambda : list(map(int,strInp()))


for i in range(int(input())):
    n = int(input())
    tany = math.tan(math.pi/(2*n))
    print(1/tany)