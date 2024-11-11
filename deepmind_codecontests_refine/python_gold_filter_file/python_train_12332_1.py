a = list(map(int, input().split()))
n = int(input())

s = [1, 2, 3, 4, 5]
m = [2, 3, 1, 4, 5]
l = [3, 4, 2, 5, 1]
xl = [4, 5, 3, 2, 1]
xxl = [5, 4, 3, 2, 1]

for inp in range(n):
    x = input()

    if x == 'S':
        for i in range(5):
            if a[s[i]-1] > 0:
                a[s[i]-1] -= 1
                ans = s[i]
                break
    if x == 'M':
        for i in range(5):
            if a[m[i]-1] > 0:
                a[m[i]-1] -= 1
                ans = m[i]
                break
    if x == 'L':
        for i in range(5):
            if a[l[i]-1] > 0:
                a[l[i]-1] -= 1
                ans = l[i]
                break
    if x == 'XL':
        for i in range(5):
            if a[xl[i]-1] > 0:
                a[xl[i]-1] -= 1
                ans = xl[i]
                break
    if x == 'XXL':
        for i in range(5):
            if a[xxl[i]-1] > 0:
                a[xxl[i]-1] -= 1
                ans = xxl[i]
                break

    if ans == 1:
        print('S')
    if ans == 2:
        print('M')
    if ans == 3:
        print('L')
    if ans == 4:
        print('XL')
    if ans == 5:
        print('XXL')
        
    
