
def f(n):
    if(n<10):
        return max(1, n)
    return max((n % 10) * f(n//10), 9 * f(n//10-1))

n = int(input())
print(f(n))

