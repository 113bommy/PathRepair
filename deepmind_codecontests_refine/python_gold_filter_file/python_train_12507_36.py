n = int(input())
a = []
for i in range(n):
    l,r = map(int,input().split())
    a.append([l,r])
g = int(input())
for i in range(n):
    if a[i][0]<=g<=a[i][1]:
        print(n-i)
        break