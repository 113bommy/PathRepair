n = int(input())

# a進法でのnの桁和
def func(n,a):
    res = 0
    while n > 0:
        res += n%a
        n //= a
    return res

mini = n

for i in range(n+1):
    tmp = func(i,6) + func(n-i,9)
    mini = min(mini,tmp)
print(mini)