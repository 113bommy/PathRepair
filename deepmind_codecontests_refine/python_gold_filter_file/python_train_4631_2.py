n = input()
x = list(str(int(n[0]) if int(n[0]) < 5 or int(n[0])==9 else (9 - int(n[0]))))
u = [str(int(n[i]) if int(n[i]) < 5 else  (9 - int(n[i]))) for i in range(1, len(n))]
x.extend(u)
print("".join(x))
