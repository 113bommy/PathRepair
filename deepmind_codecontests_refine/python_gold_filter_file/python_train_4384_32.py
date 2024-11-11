a = input().split()
for i in range(len(a)):
    a[i] = int(a[i])
c = 0
sum = 0
for i in range(1,a[2]+1):
    sum =sum + 2*(a[0]-c)+(a[1]-2-c)*2
    c+=4
print(sum)
