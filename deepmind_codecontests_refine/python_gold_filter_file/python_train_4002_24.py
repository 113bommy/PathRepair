import re
s=''.join(sorted(input()))
print(["Too weak","Correct"][bool(re.search("(?=.{5})(?=[0-9]+[?]*[A-Z]+[\!\.\,\_]*[a-z]+)", s))])