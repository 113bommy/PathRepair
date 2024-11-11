import pprint
import os
import json
import re
import argparse
import random


a = input().split()
d = {'week':[52]*5+2*[53]+[52],'month':30*[12]+[11]+[7]}
print(d[a[2]][int(a[0])])
