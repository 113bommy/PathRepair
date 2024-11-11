a = int(input())
b = list(map(int, input().split()))
minimum = min(b)
to = (min(b)//a)*a
b = [k - to for k in b]
for k in range(1000000):
    allen = b[k%a]
    if allen-k <= 0:
        print(k%a+1)
        break 
