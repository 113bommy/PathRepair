n, t = map(int, input().split())
st = '';
if (n == 1 and t == 10):
    print(-1)
else:
    for i in range (n - 1):
        st += '1';
    st += '0';
    k = int(st);
    for i in range(k, k + 10):
        if i % t == 0:
            ans = i
    print(ans);
