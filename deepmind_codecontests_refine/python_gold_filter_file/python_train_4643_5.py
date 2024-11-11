al = [0]*26
bs = ord('a')
s = [ord(x)-bs for x in list(input())]
st = []
for x in s:
    al[x] += 1

cm = -1
for i in range(26):
    if al[i]:
        cm = i
        break

anso = []
for x in s:
    if x == cm:
        anso.append(x)
        al[cm] -= 1
        if not al[cm]:
            for i in range(cm,26):
                if al[i]:
                    cm = i
                    break
            while st and st[-1] <= cm:
                anso.append(st.pop())
    else:
        al[x] -= 1
        st.append(x)
ans = ''
for x in anso:
    ans += chr(bs+x)
for x in st[::-1]:
    ans += chr(bs+x)
print(ans)
