

for i in range(int(input())):
    s , a , b , c = map(int , input().split())
    p = s // (a * c)
    q = s - (p * a * c)
    print((p * a) + (p * b) + (q // c))
    