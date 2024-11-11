def compute_number_of_recolors(n, s, pattern):
    counter = 0
    for i in range(0,n):
        if s[i] != pattern[i%3]:
            counter = counter + 1
    return counter

n = int(input())
s = input()

p0 = "RBG"
p1 = "RGB"
p2 = "BRG"
p3 = "BGR"
p4 = "GRB"
p5 = "GBR"
PATTERNS = [p0, p1, p2, p3, p4, p5]
NUMBER_OF_PATTERNS = 6
res = n

for i in range(0,NUMBER_OF_PATTERNS):
    recolors = compute_number_of_recolors(n, s, PATTERNS[i])
    if res >= recolors:
        res = recolors
        patern = PATTERNS[i]

print(res)
print((patern*n)[0:n])