#Input
commands = [int(s) for s in input().split(',')]

toPrint = [False] * 1002;
for i in commands:
    toPrint[i] = True;

res = ""
seq = False;
deb = -1;
for i in range(1002):
    if toPrint[i] and not(seq):
        seq = True;
        deb = i;
        res += str(i);
    elif not(toPrint[i]) and seq:
        seq = False;
        if deb != i-1:
            res += "-" + str(i-1);
        res += ",";



print(res[:-1])
