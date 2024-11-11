for _ in range(int(input())):
    s = input().split()
    a, b = int(s[0]), int(s[1])
    a, b = max(a, b), min(a, b)
    cnt = 0
    if a-b >= 5:
        n = (a-b)//5
        cnt += n
        a -= n*5
    if a-b >= 2:
        n = (a-b)//2
        cnt += n
        a -= n*2
    cnt += (a-b)
    print(cnt)        
