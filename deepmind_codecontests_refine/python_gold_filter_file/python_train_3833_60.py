A,B,C=map(int,input().split())
print(B+C if A+B>=C-1 else A+2*B+1)