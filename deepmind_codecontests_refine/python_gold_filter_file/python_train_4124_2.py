
n = int(input())
a = list(map(int, input().split()))
i = 0
j = n - 1
flag = False
while i < n - 1 and a[i] < a[i + 1]:
     i += 1
while j > 0 and a[j - 1] > a[j]:
     j -= 1
if a[i] == a[j]:
     for k in range(i, j + 1):
          if a[k] != a[i]:
               print('NO')
               flag = True
               break
     if not flag:
          print('YES')
else:
     print('NO')
     

     
