N,K=map(int,input().split())
s=list(input())

s[K-1]=chr(ord(s[K-1])+32)
print("".join(s))