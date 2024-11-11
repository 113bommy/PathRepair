n = int(input());
e = "aeiuoy";
s = input();
q = 0;
while q < len(s) - 1:
    if s[q] in e and s[q + 1] in e:
        s = s[:q + 1] + s[q + 2:];
        q = q - 1;
    q = q + 1;
print(s);