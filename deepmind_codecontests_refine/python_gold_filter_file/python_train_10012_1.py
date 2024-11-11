num = int(input())
for i in range(num):
    nobodycares=input()
    x = list(map(int, input().split()))
    b1 = max(x)
    x.remove(b1)
    b2 = max(x)
    x.remove(b2)
    if (len(x) < b2):
        print(len(x))
    else:
        print(b2 - 1)