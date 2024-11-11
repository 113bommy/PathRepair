A = input()
st = [(0, 0, -1)]
cur = 0; ma = 0
for i, a in enumerate(A):
    if a == '/':
        cur += 1
        s = 0
        while st and st[-1][0] == cur-1 and cur <= ma:
            lev, su, j = st.pop()
            s += su
        if st and st[-1][0] == cur:
            s += i - st[-1][2] - 1
        ma = max(ma, cur)
        st.append((cur, s, i))
    elif a == '\\':
        cur -= 1
        st.append((cur, 0, i))
    elif a == '_':
        st.append((cur, 0, i))
ans = []
for lev, su, j in st:
    if su > 0:
        ans.append(su)
print(sum(ans))
print(len(ans), *ans)
