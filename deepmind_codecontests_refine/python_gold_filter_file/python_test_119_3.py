t = int (input())
for i in range (t):
    n = int(input())
    a = list(map(int , input().split()))
    s = sum(a)
    baghi = s % n 
    if baghi > 0 :
        print(1)

    else:
        print(0)