t = int(input())
st = []
st_size = 0
ans = 0
mx = 4294967296
f = False
for i in range(t):
    inp = input()
    if inp == 'add':
        if st_size == 0:
            ans += 1
        else:
            ans += st[-1]
    elif inp == 'end':
        st_size -= 1
        st.pop()
    else:
        if st_size == 0:
            st.append(int(inp[4:]))
        else:
            st.append(min(mx, st[-1]*int(inp[4:])))
        st_size += 1
    if ans >= mx :
        print("OVERFLOW!!!")
        f = True
        break
if f == False :
    if ans >= mx:
        print("OVERFLOW!!!")
    else:
        print(ans)