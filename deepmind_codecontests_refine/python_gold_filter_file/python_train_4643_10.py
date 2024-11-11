s = input()
prefmin = ['{'] * (len(s) + 1)
st = []

for i in range(len(s) - 1, -1, -1):
    prefmin[i] = min(s[i], prefmin[i + 1])

for i in range(len(s)):
    while len(st) and st[-1] <= prefmin[i]:
        print(st.pop(), end='')
    if prefmin[i] == s[i]:
        print(s[i], end='')
    else:
        st.append(s[i])

for i in range(len(st) - 1, -1, -1):
    print(st[i], end='')

