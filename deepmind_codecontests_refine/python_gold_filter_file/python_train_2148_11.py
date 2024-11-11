n = int(input())
arr = list(map(int,input().split()))
was = ["N"]*200500
for i in range(n):
    was[arr[i]] = i
m = 99999999999
ind = 0
for i in range(200500):
    if was[i] != "N":
        if was[i] < m:
            m = was[i]
            ind = i
print(ind)