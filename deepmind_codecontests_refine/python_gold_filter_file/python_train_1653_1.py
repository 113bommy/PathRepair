w_a = [1,2,4,8,16,32,64,128,256,512]

while True:
    try:
        w_b = int(input())
        b = list(bin(w_b))[::-1]
        w_c = []
        for i in range(len(b)):
            if b[i] == "b":
                break
            elif b[i] == "1":
                w_c.append(w_a[i])
        print(*w_c)
    except:
        break

