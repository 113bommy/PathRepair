def fact(a):
    s = 1
    for i in range(1, a+1):
        s*=i
    return s
 
A, B = map(int, input().split())
print(fact(min(A,B)))