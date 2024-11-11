import sys
import math

studentsNum = int(sys.stdin.readline())
messagesLimit = [int(c) for c in sys.stdin.readline().split()]
firstLimit = messagesLimit[0]
messagesLimit = sorted(enumerate(messagesLimit), key = lambda v: v[1], reverse = True)

messagesLimit.remove((0, firstLimit))
messagesLimit.insert(0, (0, firstLimit))

lastSender = 0
lastReciever = 0

pairs = []
while lastReciever < studentsNum and messagesLimit[lastSender][1] > 0:
    for reciever in range(lastReciever+1, min(studentsNum, lastReciever+messagesLimit[lastSender][1]+1)):
        pairs.append((messagesLimit[lastSender][0]+1, messagesLimit[reciever][0]+1))
    lastReciever += messagesLimit[lastSender][1]
    lastSender += 1

if lastReciever+1 < studentsNum:
    print(-1)

else:
    print(len(pairs))
    for p in pairs:
        print(p[0], p[1])