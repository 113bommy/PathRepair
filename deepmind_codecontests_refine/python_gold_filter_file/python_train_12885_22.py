s = input()
t = input()
print(sum(si != ti for si, ti in zip(s, t)))