# ANSHUL GAUTAM
# IIIT-D

from math import *
from copy import *
from string import *
from sys import stdin
from itertools import *

masha,egor,initially_lift,t_stairs,t_elevators,t_doors = map(int, input().split())
t_using_stairs = 0
t_using_elevators = 0

# using stairs

floors = abs(masha - egor)
t_using_stairs = floors*t_stairs

# using_elevators

diff = abs(masha - initially_lift)
time_for_door = 3*t_doors
t_using_elevators = diff*t_elevators
floors = abs(masha - egor)
t_using_elevators += floors*t_elevators
t_using_elevators += time_for_door
if(t_using_elevators > t_using_stairs):
	print("NO")
else:
	print("YES")