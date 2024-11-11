input()
ss = input()
loss = ss[1:].count("E")
min_loss = loss
ss_before = ss[:-1]
ss_after = ss[1:]
for b, a in zip(ss_before, ss_after):
    loss += b == "W"
    loss -= a == "E"
    if loss < min_loss:
        min_loss = loss
print("{}".format(min_loss))