def res(cost, time):
    return max(3*cost // 10, cost - cost // 250 * time)

a,b,c,d = map(int,input().split())

if res(a,c) > res(b,d):
    print("Misha")
elif res(a,c) == res(b,d):
    print("Tie")
else:
    print("Vasya")

