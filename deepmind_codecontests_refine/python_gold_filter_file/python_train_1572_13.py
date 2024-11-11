n = int(input())
l = input().split()
l = [int(i) for i in l]
l.sort()

m = (l[2*n - 1] - l[n])*(l[n - 1] - l[0])
for i in range(1,n):
        if m > (l[2*n - 1] - l[0])*(l[i + n - 1] - l[i]):
                m = (l[2*n - 1] - l[0])*(l[i + n - 1] - l[i]);
print(m)
