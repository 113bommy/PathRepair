g_data = input().split()
for i, s in enumerate(g_data):
    g_data[i] = int(s)
    
num = g_data[0]
hop = g_data[1]

box = input()

start = box.index('G')
end = box.index('T')

distance = end - start
# print("hop: {} start:{} end:{} distance:{}".format(hop, start, end, distance))

if distance % hop != 0:
    print("NO")
else:
    if end < start:
        hop *= -1
    obstacle = False
    for cell in range(start, end + 1, hop):
        if cell >= 0 and cell < num:
            if box[cell] is "#":
                obstacle = True
                break
    print("NO" if obstacle else "YES")