#!/usr/bin/python3
# -*- config:utf-8 -*-

from sys import stdin
from math import ceil


def getdata():
    s = stdin.readline()
    s = s.rstrip()
    s = s.split(' ')
    s = [int(i) for i in s]
    a, ta = s
    s = stdin.readline()
    s = s.rstrip()
    s = s.split(' ')
    s = [int(i) for i in s]
    b, tb = s
    s = stdin.readline()
    s = s.rstrip()
    s = s.split(':')
    s = [int(i) for i in s]
    dth, dtm = s
    dtm = dth * 60 + dtm
    return (a, ta, b, tb, dtm)


def getfile():
    f = open("test.txt")
    s = f.readline()
    s = s.rstrip()
    s = s.split(' ')
    s = [int(i) for i in s]
    a, ta = s
    s = f.readline()
    s = s.rstrip()
    s = s.split(' ')
    s = [int(i) for i in s]
    b, tb = s
    s = f.readline()
    s = s.rstrip()
    s = s.split(':')
    s = [int(i) for i in s]
    dth, dtm = s
    dtm = dth * 60 + dtm
    f.close()
    return (a, ta, b, tb, dtm)


def run1():
    starttime = 5 * 60
    endtime = 23 * 60 + 59
    # a,ta,b,tb,dtm=getdata()
    a, ta, b, tb, dtm = getfile()
    b_first_dt = dtm - tb
    if b_first_dt < starttime:
        b_first_dt = 0
    else:
        b_first_dt = b_first_dt - starttime
    b_last_dt = dtm + ta
    if b_last_dt > endtime:
        b_last_dt = endtime - starttime
    else:
        b_last_dt = b_last_dt - starttime
    b_first_dt = ceil(b_first_dt / b) * b
    if b_first_dt > endtime - starttime:
        b_first_dt -= b
    b_last_dt = b_last_dt // b * b
    cnt = (b_last_dt - b_first_dt) // b + 1
    if b_last_dt == (dtm + ta - starttime):
        cnt -= 1
    print(cnt)


def check_time(bus_departure_time, starttime, endtime):
    if bus_departure_time < starttime:
        return starttime
    if bus_departure_time > endtime:
        return endtime
    return bus_departure_time


def get_actual_first(first_bus_departure_time, starttime, endtime, b):
    tmp = ceil((first_bus_departure_time - starttime) / b) * b
    if tmp > (endtime - starttime):
        tmp = endtime - starttime
    return tmp


def get_actual_last(last_bus_departure_time, starttime, endtime, b):
    tmp = (last_bus_departure_time - starttime) // b * b
    if tmp > (endtime - starttime):
        tmp = endtime - starttime
    return tmp


def run():
    starttime = 5 * 60
    endtime = 23 * 60 + 59
    a, ta, b, tb, dtm = getdata()
    # a,ta,b,tb,dtm=getfile()
    first_bus_departure_time = dtm - tb
    last_bus_departure_time = dtm + ta
    first_bus_departure_time = check_time(first_bus_departure_time, starttime, endtime)
    last_bus_departure_time = check_time(last_bus_departure_time, starttime, endtime)
    first_bus_departure_time = get_actual_first(first_bus_departure_time, starttime, endtime, b)
    last_bus_departure_time = get_actual_last(last_bus_departure_time, starttime, endtime, b)
    cnt = (last_bus_departure_time - first_bus_departure_time) // b + 1
    if (dtm + ta - starttime) == last_bus_departure_time:
        cnt -= 1
    if (dtm - starttime) == first_bus_departure_time + tb:
        cnt -= 1
    print(cnt)


if __name__ == "__main__":
    run()
