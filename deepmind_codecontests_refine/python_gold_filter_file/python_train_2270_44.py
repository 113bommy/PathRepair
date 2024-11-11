n,k=map(int,input().split())
s=list(input())
s[k-1]=chr(ord(s[k-1])+32)
 
print(*s,sep='')