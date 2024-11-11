n,k = map(int,input().split())
a = list(input())
a[k-1]= a[k-1].lower()
print(''.join(a))