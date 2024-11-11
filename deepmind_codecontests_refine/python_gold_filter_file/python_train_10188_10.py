n = int(input())
p = list(map(int,input().split()))
a = [30000*i+1 for i in range(n)]
b = [30000*(n-i) for i in range(n)]
for i in range(n):
    b[p[i]-1]+=i
for i in a:
    print(i,end =' ')
print()
for i in b:
    print(i,end=' ')
print()