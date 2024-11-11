# input = sys.stdin.readline
from bisect import *
from collections import *
from heapq import *

H,W,N=map(int,input().split())
sr,sc=map(int,input().split())
S=input()
T=input()


st=0
end=W-1
sttate=0
endtate=H-1
for i in range(N-1,-1,-1):
    if T[i]=="L":
        if end<W-1:
            end+=1
    if T[i]=="R":
        if st>0:
            st-=1
    if T[i]=="U":
        if endtate<H-1:
            endtate+=1
    if T[i]=="D":
        if sttate>0:
            sttate-=1

    if S[i]=="L":
        st+=1
    if S[i]=="R":
        end-=1
    if S[i]=="U":
        sttate+=1
    if S[i]=="D":
        endtate-=1
    if st>end or sttate>endtate:
        print("NO")
        exit()

if st<=sc-1<=end and sttate<=sr-1<=endtate:
    print("YES")
else:
    print("NO")
