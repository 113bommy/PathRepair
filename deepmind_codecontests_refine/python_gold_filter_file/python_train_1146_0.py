N = int(input())
*H, = map(int, input().split())
st = [(0, -1)]
ans = 0
for i in range(N):
    h = H[i]
    base = i
    while st and h <= st[-1][0]:
        h0, j = st.pop()
        ans = max(ans, (i-j)*h0)
        base = j
    st.append((h, base))
while st:
    h0, j = st.pop()
    ans = max(ans, (N-j)*h0)
print(ans)