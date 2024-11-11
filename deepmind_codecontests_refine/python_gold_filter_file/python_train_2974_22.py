from sys import stdin
import re

regex = re.compile(r"ogo(go)*")
lines = stdin.readlines()

outString = re.sub(regex, "***", lines[1])
print(outString)