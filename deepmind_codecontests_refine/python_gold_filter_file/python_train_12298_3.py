import sys
# import logging
# logging.root.setLevel(logging.INFO)

n,p1,p2,p3,t1,t2 = list(map(int,sys.stdin.readline().strip().split()))
cost = [p3] * 2000
periods = []
for _ in range(n):
    period = list(map(int,sys.stdin.readline().strip().split()))
    periods.append(period)
    normal_end = period[1]+t1
    for t in range(period[0],normal_end):
        cost[t] = p1
    
    screensaver_begin = normal_end
    for t in range(screensaver_begin,screensaver_begin+t2):
        cost[t] = p2
begin = periods[0][0]
end = periods[-1][1]

# for i,p in enumerate(cost[:end]):
#     logging.info(f"{i} {p}")
print(sum(cost[begin : end]))







# Input
# 1
# 1
# Participant's output
# 0 1
# Jury's answer
# 1 0
# Checker comment
# wrong answer 1st numbers differ - expected: '1', found: '0'
