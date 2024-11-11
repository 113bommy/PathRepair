import queue
n ,s = map(int,input().split())
arr = list(map(int,input().split()))
m = []
st = set()
L = queue.Queue(maxsize=s)
for i in range(n):
    if L.full()!= True and arr[i] not in st:
        st.add(arr[i])
        L.put(arr[i])
    elif L.full()== True and arr[i] not in st:
        x = L.get()
        st.remove(x)
        L.put(arr[i])
        st.add(arr[i])


while L.empty() == False:
    x= L.get()
    m.append(x)

print(len(m))
print(*m[::-1])

