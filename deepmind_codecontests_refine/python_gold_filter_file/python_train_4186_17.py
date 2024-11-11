for _ in range(int(input())):
    n = int(input())
    s = input()
    fs = s.find('1')
    ans = (n-fs)*2
    sc = s.rfind('1')
    ans = max((sc+1)*2,ans)
    print(ans if fs != -1 else n)
