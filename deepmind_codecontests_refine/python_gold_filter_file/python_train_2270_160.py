A,B=map(int,input().split())
C=input()
print(C[:B-1]+C[B-1].lower()+C[B:])