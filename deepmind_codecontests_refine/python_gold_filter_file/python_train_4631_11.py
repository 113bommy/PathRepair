n = input()
x = [str(int(n[i]) if int(n[i]) < 5 else  (9 - int(n[i]))) for i in range(len(n))]
if(x[0] == "0"):
    x[0] = "9"
print("".join(x))
