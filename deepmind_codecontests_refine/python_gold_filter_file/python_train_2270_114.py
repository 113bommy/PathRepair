n,k=map(int,input().split())
a=list(input())
a[k-1]=chr(ord(a[k-1])+32)
print("".join(a))