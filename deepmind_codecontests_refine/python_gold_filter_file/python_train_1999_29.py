n, k = map(int, input().split())
a = [int(i) for i in input().split()]
screen = []
st = set()
for i in range(n):
    if len(screen) < k and a[i] not in st:
        screen.insert(0, a[i])
        st.add(a[i])
    elif len(screen) == k and a[i] not in st:
        num = screen.pop()
        st.remove(num)
        screen.insert(0, a[i])
        st.add(a[i])
print(len(screen))
print(*screen)