t = int(input())
for test in range(t):
    n = int(input())
    time = []
    ans = []
    for i in range(5001):
        time.append(0)
    for i in range(1000):
        ans.append(0)
    for i in range(n):
        buf = input().split()
        l = int(buf[0])
        r = int(buf[1])
        j = l
        while(True):
            if (j==r and time[j]==0):
                time[j] = 1
                ans[i] = j
                break
            if (j==r):
                break
            if (time[j]==0):
                time[j] = 1
                ans[i] = j
                break;
            j+=1
    for i in range(n):
        print(ans[i], end=' ');
    print("")