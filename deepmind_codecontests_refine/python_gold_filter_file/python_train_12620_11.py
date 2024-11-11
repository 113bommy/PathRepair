n = int(input())
m = list(map(int, input().split()))
assert len(m) == n

st = [(m[0], 0)]
left = [m[0]] + [0] * (n-1)
for i in range(1, len(m)):
    if m[i] >= m[i-1]:
        left[i] = left[i-1] + m[i]
    else:
        while st and st[-1][0] > m[i]:
            st.pop()
        if st:
            left[i] = left[st[-1][1]] + (i - st[-1][1]) * m[i]
        else:
            left[i] = (i + 1) * m[i]
    st.append((m[i], i))

st = [(m[n-1], n-1)]
right = [0] * (n-1) + [m[n-1]]
for i in range(n-2, -1, -1):
    if m[i] >= m[i+1]:
        right[i] = right[i+1] + m[i]
    else:
        while st and st[-1][0] > m[i]:
            st.pop()
        if st:
            right[i] = right[st[-1][1]] + (st[-1][1] - i) * m[i]
        else:
            right[i] = (n - i) * m[i]
    st.append((m[i], i))

mx, mxi = 0, -1
for i in range(n):
    area = left[i] + right[i] - m[i]
    if mx < area:
        mx = area
        mxi = i

for i in range(mxi-1, -1, -1):
    if m[i] > m[i+1]:
        m[i] = m[i+1]
for i in range(mxi+1, n):
    if m[i] > m[i-1]:
        m[i] = m[i-1]

print(' '.join(map(str, m)))
