L = int(input())

n = 0
while 2**n <= L:
    n += 1

side_lst = []
    
rest = L - 2**(n-1)
next_num = 2**(n-1)

m = n
while rest > 0:
    if rest >= 2**(m-2):
        side_lst.append([m-1, n, next_num])
        next_num += 2**(m-2)
        rest -= 2**(m-2)
    m -= 1
    
print(n, len(side_lst)+(n-1)*2)
for i in side_lst:
    print(i[0], i[1], i[2])
    
for i in range(1, n):
    print(i, i+1, 0)
    print(i, i+1, 2**(i-1))