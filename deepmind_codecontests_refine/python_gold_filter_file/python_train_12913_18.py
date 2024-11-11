import sys, string

lines = []
for line in sys.stdin:
    lines.append(line)

text = ''.join(lines).lower()
    
for char in string.ascii_lowercase:
    print("{} : {}".format(char, text.count(char)))