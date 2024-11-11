'''
Python Input
n = int(input())
a = list(map(int, input(' ').split()))
x, y = map(int, input().split())
'''



T = int(input())
while T:
    T -= 1
    n, k = map(int, input().split())    
    a = list(map(int, input('').split()))
    a.sort()
    ans = 0
    for i in range(1, n):
        ans += (k - a[i]) // a[0]
    print(ans) 

# print(math.factorial(88986))
