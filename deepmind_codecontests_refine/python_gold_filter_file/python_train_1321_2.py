import sys
# import logging
# logging.root.setLevel(level=logging.INFO)

y,w = map(int,sys.stdin.readline().strip().split())
cases = ["0/1","1/6","1/3","1/2","2/3","5/6","1/1"]
print(cases[6-max(y,w)+1])