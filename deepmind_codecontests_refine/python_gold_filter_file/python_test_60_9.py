t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = 2*sum(a)/n
    if(s != s//1):
        print(0)
    else:
        count = 0
        c = dict()
        for i in a:
            if(i in c):
                c[i] += 1
            else:
                c[i] = 1
        for i, num in c.items():
            if(i <= s and 2*i != s):
                sec = s - i
                if(sec in c):
                    count += num * c[sec]
            elif(2*i == s):
                count += 2*((num*(num-1))//2)    
        print(count//2)
