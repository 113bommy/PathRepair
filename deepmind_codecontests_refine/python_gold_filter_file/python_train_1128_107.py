from collections import Counter as C
n=int(input())
A=sorted(C(list(map(lambda x:min(x//400,8),list(map(int,input().split()))))+[8]).most_common())
print(len(A)-1 if A[0][0]!=8 else 1,len(A)+A[-1][1]-2)