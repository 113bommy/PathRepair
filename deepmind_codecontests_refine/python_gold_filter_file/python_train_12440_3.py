n = int(input())
a = [int(i) for i in input().split()]
for i in range (n):
    while a[i] % 2 == 0:
        a[i] = a[i]// 2
    while a[i] % 3 == 0:
        a[i] = a[i]// 3
r = 0;
for i in range (n-1):
     if a[i] != a[i+1]:
        r = 1;
if r:
    print('No')
else:
    print ('Yes')
    
